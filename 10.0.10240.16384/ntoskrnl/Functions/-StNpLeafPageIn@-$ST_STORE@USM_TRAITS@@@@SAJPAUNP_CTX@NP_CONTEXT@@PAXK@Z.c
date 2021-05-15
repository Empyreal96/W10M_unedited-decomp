// -StNpLeafPageIn@-$ST_STORE@USM_TRAITS@@@@SAJPAUNP_CTX@NP_CONTEXT@@PAXK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StNpLeafPageIn(int a1, int a2, unsigned int a3, int a4)
{
  unsigned int v4; // r6
  _DWORD *v5; // r5
  int v8; // r4
  int result; // r0
  unsigned int v10; // [sp+8h] [bp-20h] BYREF
  int v11; // [sp+Ch] [bp-1Ch]

  v10 = a3;
  v11 = a4;
  v4 = 0;
  v5 = *(_DWORD **)(*(_DWORD *)a1 + 84);
  v8 = 0;
  while ( 1 )
  {
    result = ST_STORE<SM_TRAITS>::StDmSinglePageRetrieveSync(v5, a3 & 0xFFFFFFFC, a2, 0);
    if ( result >= 0 )
      break;
    if ( (v5[18] & 0x2000) == 0 || result != -2147483626 || v8 || v4 >= 0x1C9C380 )
      return result;
    v8 = ((unsigned __int64)v4 + 500000) >> 32;
    v4 += 500000;
    StEtaIoTimeout(v5[69]);
    v10 = 500000;
    v11 = 0;
    KeDelayExecutionThread(0, 0, &v10);
  }
  return 0;
}
