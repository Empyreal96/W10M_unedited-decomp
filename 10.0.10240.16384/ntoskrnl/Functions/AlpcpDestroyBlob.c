// AlpcpDestroyBlob 
 
int __fastcall AlpcpDestroyBlob(int a1)
{
  _DWORD *v2; // r5
  int (*v3)(void); // r3
  int result; // r0
  int (__fastcall **v5)(int, unsigned int, int); // r5
  unsigned int v6; // r2
  unsigned int v7; // r0

  v2 = (_DWORD *)AlpcpRegisteredTypes[*(unsigned __int8 *)(a1 - 15)];
  v3 = (int (*)(void))v2[6];
  if ( !v3 || (result = v3(), result >= 0) )
  {
    if ( (*(_BYTE *)(a1 - 16) & 2) != 0 )
    {
      v5 = &AlpcpLookasides[32 * v2[2]];
      v6 = *((unsigned __int16 *)v5 + 4);
      v5[5] = (int (__fastcall *)(int, unsigned int, int))((char *)v5[5] + 1);
      if ( *((unsigned __int16 *)v5 + 2) >= v6 )
      {
        v5[6] = (int (__fastcall *)(int, unsigned int, int))((char *)v5[6] + 1);
        result = ((int (__fastcall *)(int))v5[11])(a1 - 24);
      }
      else
      {
        result = RtlpInterlockedPushEntrySList((unsigned __int64 *)v5, (_DWORD *)(a1 - 24));
      }
    }
    else
    {
      v7 = a1 - 24;
      if ( v2[7] )
        result = ((int (__fastcall *)(unsigned int))AlpcpLookasides[32 * v2[2] + 11])(v7);
      else
        result = ExFreePoolWithTag(v7);
    }
  }
  return result;
}
