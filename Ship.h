#include "Macros.h"
#include "raylib.h"

class Ship
{
    public:

        void Maneuver()
        {
            if(IsKeyDown(87))
            {
                Posy-=2;
            }
            if(IsKeyDown(83))
            {
                Posy+=2;
            }
            if(IsKeyDown(65))
            {
                Posx-=2;
            }
            if(IsKeyDown(68))
            {
                Posx+=2;
            }                        

        }

        void CalculateNode()
        {
            N1x=Posx+Basehalved;
            N1y=Posy+Heighthalved;

            N2x=Posx;
            N2y=Posy-Heighthalved;

            N3x=Posx-Basehalved;
            N3y=Posy+Heighthalved;
        }

        void TrackShip()
        {
            CalculateNode();
            Vector2 Node1={N1x,N1y};
            Vector2 Node2={N2x,N2y};
            Vector2 Node3={N3x,N3y};
            DrawTriangle(Node1,Node2,Node3,GREEN);
        }

        int GetNode(int x, char y)
        {
            if(y == 'x')
            {
                switch(x)
                {
                    case 1:
                        return(N1x);
                        break;
                    case 2:
                        return(N2x);
                        break;
                    case 3:
                        return(N3x);
                        break;
                }
            }
            else if(y=='y')
            {
                switch(x)
                {
                    case 1:
                        return(N1y);
                        break;
                    case 2:
                        return(N2y);
                        break;
                    case 3:
                        return(N3y);
                        break;
                }
            }
        }

    private:

        int Posx=CENTROX;
        int Posy=CENTROY;

        int Basehalved = 20;
        int Heighthalved = 25;

        int N1x;
        int N1y;

        int N2x;
        int N2y;

        int N3x;
        int N3y;

        Vector2 Node1;
        Vector2 Node2;
        Vector2 Node3;
};