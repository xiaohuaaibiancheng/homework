import sys
from time import sleep
import pygame

from settings import Settings
from ship import Ship
from bullet import Bullet
from alien import Alien
from game_stats import GameStats
from bottom import Buttom 
from scoreboard import Scoreboard

class AlienInvasion:
    def __init__(self):
        """初始化游戏并创建游戏资源"""
        pygame.init()
        self.clock = pygame.time.Clock()#初始化时钟
        # self.screen = pygame.display.set_mode((1200,800))
        pygame.display.set_caption('Alien Invasion')#标题名
        self.settings=Settings()#setting类
        """设置全屏的方法"""
        # self.screen =pygame.display.set_mode((0,0),pygame.FULLSCREEN)
        self.screen = pygame.display.set_mode((self.settings.screen_width,self.settings.screen_height))
        self.ship=Ship(self)
        self.bullets=pygame.sprite.Group()#多个元素可以用编组来存储
        self.aliens=pygame.sprite.Group()

        self._create_fleet()
        #创建存储游戏统计信息的实例，并创建计分牌
        
        self.stats =GameStats(self)
        self.sb=Scoreboard(self)
        self.game_active =False

        #创建Play按钮
        self.play_button =Buttom(self,"Let's begin")

    def _create_fleet(self):
        """创建一个外星舰队"""
        #创建一个外星，再不断添加，直到没有空间添加外星人为止
        #外星人的间距为外星人的宽度
        #外星人的间距为外星人的宽度和高度
        alien=Alien(self)
        alien_width, alien_height=alien.rect.size

        current_x,current_y=alien_width,alien_height
        while current_y < (self.settings.screen_height-3*alien_height):
            while current_x < (self.settings.screen_width-2*alien_width):
                self._create_alien(current_x,current_y)
                current_x+=2*alien_width
             #添加一行外星人后重置x值并递增y值
            current_x=alien_width
            current_y+=2*alien_height

    def _create_alien(self,x_position,y_position):
        """创建一个外星人并把它放在行中"""
        new_alien = Alien(self)
        new_alien.x=x_position
        new_alien.rect.x=x_position
        new_alien.rect.y=y_position
        self.aliens.add(new_alien)#将new_alien对象存在aliens编组里



    def run_game(self):
        """开始游戏的主循环"""
        while True:
            self._check_event()
            self._update_screen()
            self.clock.tick(80)#刷新频率
            self.ship.update()

            if self.game_active:    
                self.bullets.update()
                self._update_bullets()
                self._update_aliens()
                
            

    def _check_event(self):
        #侦听键盘和鼠标事件
        for event in pygame.event.get():
                if event.type == pygame.QUIT: #退出标志
                    sys.exit()
                elif event.type==pygame.KEYDOWN:
                    self._check_keydown_event(event)
                elif event.type==pygame.KEYUP:
                   self._check_keyup_event(event)
                elif event.type==pygame.MOUSEBUTTONDOWN:
                    mouse_pos=pygame.mouse.get_pos()
                    self._check_play_button(mouse_pos)


    def _check_keyup_event(self,event):
        """响应向上"""
        if event.key==pygame.K_RIGHT:
            self.ship.moving_right=False
        elif event.key==pygame.K_LEFT:
            self.ship.moving_left=False

    def _check_keydown_event(self,event):
        """响应向下"""
        if event.key==pygame.K_RIGHT:
            #飞船向右移动
            self.ship.moving_right=True
        elif event.key==pygame.K_LEFT:
             #飞船向左移动
            self.ship.moving_left=True
        elif event.key==pygame.K_q:#按q则退出，但是分中英文,移动键也分中英文
            sys.exit()
        elif event.key==pygame.K_SPACE:
            self._fire_bullet()

    def _check_play_button(self,mouse_pos):
        """在玩家点击Play键时开始新游戏"""
        button_clicked=self.play_button.rect.collidepoint(mouse_pos)#collidepoint检查鼠标点击是否在rect范围内
        if button_clicked and not self.game_active:#只有当鼠标点击范围在规定位置和游戏处于非活跃时点击才有效
            #还原游戏设置
            self.settings.initialize_dynamic_settings()
            #重置游戏的统计信息
            self.stats.reset_stats()
            self.sb.prep_score()
            self.sb.prep_level()
            self.sb.prep_ships()
            self.game_active=True

            #清空外星人和子弹列表
            self.bullets.empty()
            self.aliens.empty()
            
            #创建一个新的外星人舰队,并让飞船在屏幕中央显示
            self._create_fleet()
            self.ship.center_ship()

            #隐藏光标
            pygame.mouse.set_visible(False)

    
    def _fire_bullet(self):
        """创建一颗子弹,并将其加入编组bullets"""
        if len(self.bullets) < self.settings.bullets_allowd :
            new_bullet=Bullet(self)
            self.bullets.add(new_bullet)

    def _update_bullets(self):
        """更新子弹的位置并删除已消失的子弹"""
        #更新子弹数量
        self.bullets.update()
        """删除已消失的子弹"""
        for bullet in self.bullets.copy():
            if bullet.rect.bottom < 0:
                self.bullets.remove(bullet)
        self._check_bullet_alien_collision()
        
    def _check_bullet_alien_collision(self):
        """检查是否有子弹击中了外星人
            如果是。就删除相应的子弹和外星人
        """
        collision=pygame.sprite.groupcollide(self.bullets,self.aliens,False,True)
        if collision:
            self.stats.score+=self.settings.alien_points
            self.sb.prep_score()
            self.sb.check_high_score() 

        if not self.aliens:
            #删除现有的子弹并且创造一个新的外星舰队
            self.bullets.empty()
            self._create_fleet()
            self.settings.increase_speed()

            #提高等级
            self.stats.level+=1
            self.sb.prep_level()

    def _update_aliens(self):
        """更新外星舰队所有外星人位置"""
        self.aliens.update()
        self._check_fleet_edges()

        #检测外星人和飞船之间的碰撞
        if pygame.sprite.spritecollideany(self.ship,self.aliens):
            self._ship_hit()

        #检查是否有外星人到达了屏幕的下边缘
        self._check_aliens_bottom()

    def _update_screen(self):
        #每次循环重新绘制屏幕
        self.screen.fill(self.settings.bg_color)
        for bullet in self.bullets.sprites():
            bullet.draw_bullet()
        self.ship.blitme()
        self.aliens.draw(self.screen)

        self.sb.show_score()

        if not self.game_active:
            self.play_button.draw_button()
        #让最近绘制的屏幕可见
        pygame.display.flip()

    def _check_fleet_edges(self):
        """有外星人到达边缘时有所措施"""
        for alien in self.aliens.sprites():
            if alien.check_edges():
                self._change_fleet_direction()
                break

    def _change_fleet_direction(self):
        """将整个外星人舰队向下移并改变方向"""
        for alien in self.aliens.sprites():
            alien.rect.y+=self.settings.fleet_drop_speed
        self.settings.fleet_direction*=-1

    def _ship_hit(self):
        """响应飞船和外星人的碰撞"""
        if self.stats.ships_left >0:
            #将ship_left减1，并更新计分牌
            self.stats.ships_left-=1
            self.sb.prep_ships()

            #清空外星人列表和子弹列表
            self.bullets.empty()
            self.aliens.empty()

            #创建一个新的外星人舰队,并将飞船放在屏幕底部的中央
            self._create_fleet()
            self.ship.center_ship()

            #暂停
            sleep(1)
        else:
            self.game_active=False
            pygame.mouse.set_visible(True)


    def _check_aliens_bottom(self):
        """检查是否有外星人到了屏幕的下边缘"""
        for alien in self.aliens.sprites():
            if alien.rect.bottom >= self.settings.screen_height:
                #像飞船被撞一样处理
                self._ship_hit()
                break

if __name__ == '__main__':
    #创建游戏实例并运行游戏
    ai = AlienInvasion()
    ai.run_game()

