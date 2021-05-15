// SepBuildDefaultCap 
 
int __fastcall SepBuildDefaultCap(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  _BYTE *v5; // r0
  _DWORD *v6; // r5
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[1] = a4;
  v8[0] = 0;
  v4 = SepBuildDefaultCape(v8);
  if ( v4 < 0 )
    JUMPOUT(0x81A322);
  v5 = (_BYTE *)ExAllocatePoolWithTag(1, 40, 1884513619);
  v6 = v5;
  if ( !v5 )
    return sub_81A320();
  memset(v5, 0, 40);
  v6[4] = 0;
  v6[5] = DefaultCapName;
  v6[6] = off_9201F0;
  v6[7] = 1;
  v6[8] = 1;
  v6[9] = v8[0];
  v6[3] = 0;
  SepRmDefaultCap = v6;
  return v4;
}
