#include <stdio.h>
#include <conio.h>
#include <graphics.h>



#define WIDTH 640
#define HEIGHT 480
#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 60
#define BALL_SIZE 10
#define PADDLE_MARGIN 20
#define PADDLE_SPEED 10
#define BALL_SPEED 2
#define WHITE 15
#define UP_ARROW 72
#define DOWN_ARROW 80

int main() {
    int gd = DETECT, gm;
    int paddleLeftY = HEIGHT / 2 - PADDLE_HEIGHT / 2;
    int paddleRightY = HEIGHT / 2 - PADDLE_HEIGHT / 2;
    int ballX = WIDTH / 2;
    int ballY = HEIGHT / 2;
    int ballDirectionX = -1; // -1 for left, 1 for right
    int ballDirectionY = -1; // -1 for up, 1 for down
    int gameOver = 0;
  
    printf("Welcome to Bibek's Ping Pong Game!\n");
    printf("\n");
    printf("Instructions:\n");
    printf("- Player 1 controls the left paddle using 'W' and 'S' keys.\n");
    printf("- Player 2 controls the right paddle using the up and down arrow keys.\n");
    printf("- Bounce the ball back and forth with your paddle.\n");
    printf("- If the ball hits the top or bottom boundary, it bounces back.\n");
    printf("- Let the ball pass your paddle, and the opponent scores.\n");


    initgraph(&gd, &gm, "");
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(WIDTH / 2 -270, HEIGHT / 2, "Ping Pong by Bibek");
    delay(1000);
    outtextxy(WIDTH / 2 , (HEIGHT / 2)+50, "3");
    delay(1000);
     outtextxy(WIDTH / 2 , (HEIGHT / 2)+100, "2");
    delay(1000);
    outtextxy(WIDTH / 2 , (HEIGHT / 2)+150, "1");
    delay(1000);

    while (!gameOver) {
        cleardevice();
        

        // Draw paddles
        rectangle(PADDLE_MARGIN, paddleLeftY, PADDLE_MARGIN + PADDLE_WIDTH, paddleLeftY + PADDLE_HEIGHT);
        rectangle(WIDTH - PADDLE_MARGIN - PADDLE_WIDTH, paddleRightY, WIDTH - PADDLE_MARGIN, paddleRightY + PADDLE_HEIGHT);

        // Draw ball
        circle(ballX, ballY, BALL_SIZE);

        // Move ball
        ballX += BALL_SPEED * ballDirectionX;
        ballY += BALL_SPEED * ballDirectionY;

        // Collision detection for top and bottom walls
        if (ballY <= 0 || ballY >= HEIGHT)
            ballDirectionY = -ballDirectionY;

        // Collision detection for paddles
        if ((ballX <= PADDLE_MARGIN + PADDLE_WIDTH && ballY >= paddleLeftY && ballY <= paddleLeftY + PADDLE_HEIGHT) ||
            (ballX >= WIDTH - PADDLE_MARGIN - PADDLE_WIDTH - BALL_SIZE && ballY >= paddleRightY && ballY <= paddleRightY + PADDLE_HEIGHT)) {
            ballDirectionX = -ballDirectionX;
        }

        // Check for paddle movement input
        if (kbhit()) {
            char key = getch();
            if (key == UP_ARROW && paddleRightY > 0)
                paddleRightY -= PADDLE_SPEED;
            else if (key == DOWN_ARROW && paddleRightY < HEIGHT - PADDLE_HEIGHT)
                paddleRightY += PADDLE_SPEED;
            else if (key == 'w' && paddleLeftY > 0)
                paddleLeftY -= PADDLE_SPEED;
            else if (key == 's' && paddleLeftY < HEIGHT - PADDLE_HEIGHT)
                paddleLeftY += PADDLE_SPEED;
        }

        delay(10);

        // Check for game over
        if (ballX <= 0 || ballX >= WIDTH) {
            gameOver = 1;
            outtextxy(WIDTH / 2 - 200, HEIGHT / 2, "GAME OVER!");
            delay(2000);
        }
    }

    closegraph();
    return 0;
}
