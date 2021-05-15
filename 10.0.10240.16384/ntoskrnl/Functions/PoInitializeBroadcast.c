// PoInitializeBroadcast 
 
int PoInitializeBroadcast()
{
  _BYTE *v0; // r0
  _DWORD *v1; // r4
  _DWORD *v3; // r2
  int v4; // r1
  _DWORD *v5; // r3

  v0 = (_BYTE *)ExAllocatePoolWithTag(512, 260, 1936933968);
  v1 = v0;
  if ( !v0 )
    return -1073741670;
  memset(v0, 0, 260);
  v1[3] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v1[2] = 0;
  v1[59] = v1 + 59;
  v1[60] = v1 + 59;
  v3 = v1 + 11;
  v4 = 5;
  do
  {
    *v3 = v3;
    v3[1] = v3;
    v3[2] = v3 + 2;
    v3[3] = v3 + 2;
    v3[4] = v3 + 4;
    v3[5] = v3 + 4;
    v5 = v3 + 6;
    v3 += 10;
    *v5 = v5;
    v5[1] = v5;
    --v4;
  }
  while ( v4 );
  PpmBeginHighPerfRequest();
  *(_DWORD *)&PopCurrentBroadcast = 0;
  dword_61E844 = 0;
  dword_61E848 = 0;
  dword_61E84C = (int)v1;
  PopBuildDeviceNotifyList((int)(v1 + 7));
  PopHaltDeviceIdle();
  return 0;
}
