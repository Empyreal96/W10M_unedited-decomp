// PpmPostProcessMediaBuffering 
 
void __fastcall PpmPostProcessMediaBuffering(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  void **v7; // r1
  int v8; // r0
  int v9; // r2
  int v10; // t1
  int v11; // r3

  PpmCheckApplyResetNotification();
  if ( PpmPlatformStates )
  {
    v8 = 0;
    v9 = (unsigned __int16)KeNumberNodes;
    if ( KeNumberNodes )
    {
      v7 = &KeNodeBlock;
      do
      {
        v10 = (int)*v7++;
        v8 |= *(_DWORD *)(v10 + 128);
        --v9;
      }
      while ( v9 );
    }
    v11 = dword_681D78[0] & ~v8;
    if ( v11 )
      sub_7BF0B8(v8, (int)v7, 0, v11, a5, a6, a7);
  }
}
