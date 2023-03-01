# Sea Battle Game

This is repo of Sea Battle Game, which was created as credit project in Lyceum BSU.

## Configuration

To run projects successfully you need to add some external files. 
At first you shoud place some images in `game/Win32/Debug/img` folder, which you can find in `img` folder:
```
back_buttons.bmp
background.bmp
constructor_btn.bmp
icon.ico
near.bmp
near_hit.bmp
sea.bmp
sea_hit.bmp
ship.bmp
ship_hit.bmp
ship_kill.bmp
war_btn.bmp
МОРСКОЙ БОЙ.bmp
```
Than you shoud create Microsoft Access Database file(`.mdb`) in `server/Win32/Debug` folder with such structure:
```
DB Name: ship_war.mdb
Table Name: GameRooms
Table Fields: [
  RoomId (AutoNumber),
  InviteCodeFirst (Number),
  InviteCodeSecond (Number),
  CodeIsUsedFirst (Yes/No),
  CodeIsUsedSecond (Yes/No),
  GuidFirst (Short Text),
  GuidSecond (Short Text),
  Move (Number)
]
```


## Technologies
- C++ Builder v10.3
- [sgcWebSockets package](https://www.esegece.com/websockets) 
