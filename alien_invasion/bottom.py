import pygame.font
class Buttom:
    """为游戏类创建的按钮的类"""
    def __init__(self,ai_game,msg):
        """初始化按钮的属性"""
        self.screen=ai_game.screen
        self.screen_rect=self.screen.get_rect()

        #设置按钮的尺寸和其他属性
        self.width,self.height=200,50
        self.botton_color=(0,0,200)
        self.text_color=(255,255,255)
        self.font=pygame.font.SysFont(None,48)

        #创建按钮的rect对象
        self.rect=pygame.Rect(0,0,self.width,self.height)
        self.rect.center=self.screen_rect.center

        #按钮的标签只用创建一次
        self._prep_msg(msg)

    def _prep_msg(self,msg):
        """将msg渲染成图片,并使其在按钮上居中"""
        self.msg_img=self.font.render(msg,True,self.text_color,self.botton_color)#True 里面为抗锯齿
        self.msg_img_rect=self.msg_img.get_rect()
        self.msg_img_rect.center=self.rect.center

    def draw_button(self):
        """绘制一个用颜色填充的按钮，再绘制文本"""
        self.screen.fill(self.botton_color,self.rect)
        self.screen.blit(self.msg_img,self.msg_img_rect)