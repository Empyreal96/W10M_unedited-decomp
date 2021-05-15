// CmpFlushNotify 
 
int __fastcall CmpFlushNotify(int result, int a2, int a3)
{
  unsigned int v3; // r9
  int v4; // r7
  unsigned int v5; // r4
  unsigned int v6; // [sp+10h] [bp-20h]

  if ( *(_DWORD *)(result + 8) )
  {
    if ( !a2 )
    {
      v3 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(result + 4) + 20) + 1864);
      v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      result = KeAbPreAcquire(v3, 0, 0);
      v4 = result;
      do
        v5 = __ldrex((unsigned __int8 *)v3);
      while ( __strex(v5 & 0xFE, (unsigned __int8 *)v3) );
      __dmb(0xBu);
      if ( (v5 & 1) == 0 )
        result = ExpAcquireFastMutexContended(v3, result);
      if ( v4 )
        *(_BYTE *)(v4 + 14) |= 1u;
      *(_DWORD *)(v3 + 4) = v6;
    }
    result = sub_7D1A1C(result, a2, a3);
  }
  return result;
}
