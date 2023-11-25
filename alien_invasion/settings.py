class Settings:
    '''存储外星人入侵的所有设置类'''
    def __init__(self):
        '''初始化游戏设置'''
        self.screen_width = 1200
        self.screen_height = 800
        self.bg_color = (230,230,230)
        
        #子弹设置
        self.bullet_color=(255,0,0)
        
        self.bullet_width=2.0
        self.bullet_height=2.0
        self.bullets_allowd=3
         #外星人设置
        
        self.fleet_drop_speed = 20
        
        #游戏信息设置
        self.ship_limit=3

        #加快游戏的节奏
        self.speedup_scale=1.1
        self.initialize_dynamic_settings()

        #外星人分数提高的速度
        self.score_scale=1.5

    def initialize_dynamic_settings(self):
        """初始化随游戏进行而变化的设置"""
        self.bullet_speed=2.5
        self.alien_speed=1.0
        self.ship_speed=1.5
        #fleet_direction为1则表示向右，为-1表示向左
        self.fleet_direction=1

        #计分设置
        self.alien_points=50

    def increase_speed(self):
        """提高速度设置的值，和外星人的分数"""
        self.ship_speed*=self.speedup_scale
        self.bullet_speed*=self.speedup_scale
        self.alien_speed*=self.speedup_scale

        self.alien_points=int(self.alien_points*self.score_scale)
        
        