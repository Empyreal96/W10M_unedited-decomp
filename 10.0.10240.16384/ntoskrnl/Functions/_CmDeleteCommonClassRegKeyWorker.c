// _CmDeleteCommonClassRegKeyWorker 
 
int __fastcall CmDeleteCommonClassRegKeyWorker(int *a1, unsigned __int16 *a2, __int16 a3, int a4, char a5)
{
  unsigned int v6; // r6
  int v10; // r4
  unsigned __int16 *v11; // r5
  int v12; // r0
  unsigned __int16 *v13; // r6
  int v14; // r1
  int v15; // r0
  int v17; // [sp+0h] [bp-48h]
  unsigned int v18; // [sp+10h] [bp-38h] BYREF
  int v19; // [sp+14h] [bp-34h]
  int v20; // [sp+18h] [bp-30h] BYREF
  unsigned int v21[10]; // [sp+20h] [bp-28h] BYREF

  v6 = 200;
  v19 = 0;
  v20 = 0;
  v18 = 200;
  if ( (a3 & 0x200) != 0 )
  {
    v6 = 320;
    v18 = 320;
  }
  while ( 1 )
  {
    v12 = ExAllocatePoolWithTag(1, v6, 1380994640);
    v11 = (unsigned __int16 *)v12;
    if ( !v12 )
      break;
    v10 = CmGetCommonClassRegKeyPath(v12, a2, a3, a4, v17, v12, v6 >> 1, v21);
    if ( v10 != -1073741789 )
      goto LABEL_8;
    ExFreePoolWithTag((unsigned int)v11);
    v11 = 0;
    v10 = RtlULongLongToULong(2 * v21[0], v21[0] >> 31, &v18);
    if ( v10 < 0 )
      goto LABEL_25;
    v6 = v18;
  }
  v10 = -1073741801;
LABEL_8:
  if ( v10 >= 0 )
  {
    if ( (a3 & 0x100) != 0 )
    {
      v13 = v11;
      v10 = PnpCtxRegOpenCurrentUserKey(a1);
      if ( v10 < 0 )
        goto LABEL_25;
      v14 = v19;
    }
    else
    {
      v10 = RtlInitUnicodeStringEx((int)v21, v11);
      if ( v10 < 0 )
        goto LABEL_25;
      if ( LOWORD(v21[0]) >= v6 || LOWORD(v21[0]) <= 0x32u || !RtlPrefixUnicodeString(L"24", (unsigned __int16 *)v21, 1) )
      {
        v10 = -1073741811;
        goto LABEL_25;
      }
      v13 = v11 + 25;
      v10 = PnpCtxGetCachedContextBaseKey(a1, 4, &v20);
      if ( v10 < 0 )
        goto LABEL_25;
      v14 = v20;
    }
    if ( a5 )
      v15 = PnpCtxRegDeleteTree(a1, v14, v13);
    else
      v15 = PnpCtxRegDeleteKey(a1, v14, v13);
    if ( v15 != -1073741444 && v15 < 0 )
      v10 = v15;
  }
LABEL_25:
  if ( v19 )
    ZwClose();
  if ( v11 )
    ExFreePoolWithTag((unsigned int)v11);
  return v10;
}
