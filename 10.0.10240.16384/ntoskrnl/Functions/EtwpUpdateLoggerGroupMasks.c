// EtwpUpdateLoggerGroupMasks 
 
int __fastcall EtwpUpdateLoggerGroupMasks(int a1, int a2)
{
  unsigned __int16 *v4; // r0
  unsigned int v5; // r2
  int v7[12]; // [sp+0h] [bp-30h] BYREF

  memset(v7, 0, 32);
  if ( a2 )
  {
    v4 = EtwpGetFlagExtension(a2, 1);
    if ( v4 )
    {
      v5 = (unsigned __int16)(4 * *v4 - 4);
      if ( v5 > 0x20 )
        return -1073741811;
      memmove((int)v7, (int)(v4 + 2), v5);
    }
    else if ( *(int *)(a2 + 72) >= 0 )
    {
      v7[0] = *(_DWORD *)(a2 + 72);
    }
  }
  return EtwpUpdateGroupMasks(a1, v7);
}
