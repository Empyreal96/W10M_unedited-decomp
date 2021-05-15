// ObDeleteCapturedInsertInfo 
 
int __fastcall ObDeleteCapturedInsertInfo(int result)
{
  int v1; // r5
  int v2; // r3
  _DWORD *v3; // r0
  unsigned int v4; // r1
  int v5; // r4
  unsigned int v6; // r2
  unsigned int v7; // r2

  v1 = result;
  if ( (*(_BYTE *)(result - 9) & 1) != 0 )
  {
    v2 = *(_DWORD *)(result - 8);
    if ( v2 )
    {
      if ( *(_DWORD *)(v2 + 24) )
      {
        result = sub_7C2F2C();
      }
      else
      {
        v3 = *(_DWORD **)(result - 8);
        v4 = (unsigned int)KeGetPcr() & 0xFFFFF000;
        v5 = *(_DWORD *)(v4 + 2848);
        v6 = *(unsigned __int16 *)(v5 + 8);
        ++*(_DWORD *)(v5 + 20);
        if ( *(unsigned __int16 *)(v5 + 4) < v6
          || (++*(_DWORD *)(v5 + 24),
              v5 = *(_DWORD *)(v4 + 2852),
              v7 = *(unsigned __int16 *)(v5 + 8),
              ++*(_DWORD *)(v5 + 20),
              *(unsigned __int16 *)(v5 + 4) < v7) )
        {
          result = RtlpInterlockedPushEntrySList((unsigned __int64 *)v5, v3);
        }
        else
        {
          ++*(_DWORD *)(v5 + 24);
          result = (*(int (__fastcall **)(_DWORD *))(v5 + 44))(v3);
        }
        *(_DWORD *)(v1 - 8) = 0;
      }
    }
  }
  return result;
}
