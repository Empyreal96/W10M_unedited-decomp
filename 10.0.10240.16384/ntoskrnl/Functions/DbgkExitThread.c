// DbgkExitThread 
 
int __fastcall DbgkExitThread(int a1)
{
  unsigned int v2; // r2
  int v3; // r3
  int v4; // r2
  int result; // r0
  int v6[46]; // [sp+0h] [bp-B8h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = __mrc(15, 0, 13, 0, 3);
  v4 = *(_DWORD *)(v2 + 960);
  result = *(_DWORD *)((v3 & 0xFFFFFFC0) + 0x74);
  if ( (v4 & 4) == 0 && *(_DWORD *)(result + 340) && (v4 & 2) != 0 )
  {
    v6[8] = a1;
    v6[0] = 2359308;
    v6[1] = 8;
    v6[6] = 3;
    result = DbgkpSendApiMessage(result, 1, (int)v6);
  }
  return result;
}
