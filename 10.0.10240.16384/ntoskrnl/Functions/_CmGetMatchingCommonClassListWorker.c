// _CmGetMatchingCommonClassListWorker 
 
int __fastcall CmGetMatchingCommonClassListWorker(_DWORD *a1, int a2, int a3, int a4, _WORD *a5, unsigned int a6, unsigned int *a7)
{
  _DWORD *v7; // r5
  int v10; // r1
  int v11; // r4
  _BYTE *v12; // r0
  int v13; // r1
  int v14; // r3
  unsigned int v15; // r3
  unsigned int v16; // r3
  int v18; // [sp+0h] [bp-28h] BYREF
  int v19; // [sp+4h] [bp-24h]
  int v20; // [sp+8h] [bp-20h]

  v19 = a3;
  v20 = a4;
  v7 = 0;
  *a7 = 0;
  v18 = 0;
  if ( a6 )
    *a5 = 0;
  if ( a2 == 2 )
  {
    v10 = 7;
  }
  else
  {
    if ( a2 != 4 )
    {
      v11 = -1073741811;
      goto LABEL_12;
    }
    v10 = 8;
  }
  v11 = PnpCtxGetCachedContextBaseKey(a1, v10, &v18);
  if ( v11 < 0 )
    return v11;
  v12 = (_BYTE *)ExAllocatePoolWithTag(1, 24, 1380994640);
  v7 = v12;
  if ( !v12 )
    return -1073741801;
  memset(v12, 0, 24);
  v13 = v18;
  v14 = v19;
  *v7 = a2;
  v7[1] = v14;
  v7[2] = v20;
  v7[3] = a5;
  v7[4] = a6;
  v7[5] = 0;
  v11 = PnpCtxRegEnumKeyWithCallback(a1, v13, CmClassSubkeyCallback, v7);
  if ( v11 >= 0 )
  {
    v15 = v7[5];
    *a7 = v15;
    if ( v15 )
    {
      v16 = v15 + 1;
      *a7 = v16;
      if ( a5 && a6 >= v16 )
        a5[v16 - 1] = 0;
      else
        v11 = -1073741789;
    }
  }
LABEL_12:
  if ( v7 )
    ExFreePoolWithTag((unsigned int)v7);
  return v11;
}
