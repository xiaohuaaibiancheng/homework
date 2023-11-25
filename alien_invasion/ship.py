import pygame
from pygame.sprite import Sprite
class Ship(Sprite):
    """管理飞船的类"""
    def __init__(self,ai_game):

        #初始化飞船并设置其初始位置
        super().__init__()
        self.screen=ai_game.screen
        self.settings=ai_game.settings
        self.screen_rect=ai_game.screen.get_rect()
        

        self.image=pygame.image.load(r"C:\Users\Felix\Desktop\alien_invasion\images\ship.bmp")
        self.rect=self.image.get_rect()
        

        #每艘新飞船放在屏幕底部的中央
        self.rect.midbottom = self.screen_rect.midbottom

        #在飞船的属性x中存储一个浮点数
        self.x=float(self.rect.x)
        #移动标志，刚开始飞船不移动
        self.moving_right=False
        self.moving_left=False
        self.moving_up=False

    def center_ship(self):
        """将飞船放在屏幕最底部"""
        self.rect.midbottom=self.screen_rect.midbottom
        self.x=float(self.rect.x)
        

    def update(self):
        """根据移动标志调整位置"""
        #更新飞船属性x的值，而不是其外接矩形的属性x值
        if self.rect.right and self.moving_right < self.screen_rect.right:
            if self.moving_right:
                self.x+=self.settings.ship_speed
        if self.rect.left and self.moving_left > 0:
            if self.moving_left:
                self.x-=self.settings.ship_speed
        self.rect.x=self.x
       


    def blitme(self):
        #指定位置绘制飞船
        self.screen.blit(self.image,self.rect)
