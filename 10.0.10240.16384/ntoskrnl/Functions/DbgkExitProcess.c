// DbgkExitProcess 
 
int __fastcall DbgkExitProcess(int result)
{
  int v1; // r5
  unsigned int v2; // r2
  int v3; // r3
  int v4; // r2
  int v5; // r4
  int v6[46]; // [sp+0h] [bp-B8h] BYREF

  v1 = result;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = __mrc(15, 0, 13, 0, 3);
  v4 = *(_DWORD *)(v2 + 960);
  v5 = *(_DWORD *)((v3 & 0xFFFFFFC0) + 0x74);
  if ( (v4 & 4) == 0 && *(_DWORD *)(v5 + 340) && (v4 & 2) != 0 )
  {
    KeQuerySystemTime((_DWORD *)(v5 + 696));
    v6[0] = 2359308;
    v6[1] = 8;
    v6[6] = 4;
    v6[8] = v1;
    result = DbgkpSendApiMessage(v5, 0, (int)v6);
  }
  return result;
}
