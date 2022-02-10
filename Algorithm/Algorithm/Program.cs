// See https://aka.ms/new-console-template for more information
using Algorithm;
Console.CursorVisible = false;
const int WAIT_TICK = 1000 / 30;

int lastTick = 0;
Board board = new Board();
Player player = new Player();
board.Initialize(25, player);
player.Initialize(1,1, board);
while (true)
{
    #region 프레임관리
    int currentTick = System.Environment.TickCount;
    if (currentTick - lastTick < WAIT_TICK)
        continue;
    int deltaTick = currentTick - lastTick;
    lastTick = currentTick;
    #endregion
    // 입력

    // 로직
    player.Update(deltaTick);
    // 랜더링
    Console.SetCursorPosition(0, 0);
    board.Render();
    
}