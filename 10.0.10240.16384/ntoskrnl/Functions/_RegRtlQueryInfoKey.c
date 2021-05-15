// _RegRtlQueryInfoKey 
 
int __fastcall RegRtlQueryInfoKey(int a1, int a2, unsigned int *a3, _DWORD *a4, unsigned int *a5, _DWORD *a6)
{
  int result; // r0
  unsigned int v10; // [sp+20h] [bp-38h]
  int v11; // [sp+24h] [bp-34h]
  unsigned int v12; // [sp+28h] [bp-30h]
  int v13; // [sp+2Ch] [bp-2Ch]

  result = ZwQueryKey();
  if ( result >= 0 )
  {
    if ( a2 )
    {
      result = sub_7EE87C();
    }
    else
    {
      if ( a3 )
        *a3 = v10 >> 1;
      if ( a4 )
        *a4 = v11;
      if ( a5 )
        *a5 = v12 >> 1;
      if ( a6 )
        *a6 = v13;
    }
  }
  return result;
}
