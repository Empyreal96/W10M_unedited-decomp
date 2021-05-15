// _CmDeleteDeviceContainerRegKeyWorker 
 
int __fastcall CmDeleteDeviceContainerRegKeyWorker(int *a1, unsigned __int16 *a2, int a3, int a4, char a5)
{
  unsigned __int16 *v7; // r5
  unsigned int v9; // r6
  int v10; // r4
  int v11; // r0
  unsigned __int16 *v13; // r6
  int v14; // r1
  int v15; // r0
  int v16; // [sp+0h] [bp-40h]
  unsigned int i; // [sp+14h] [bp-2Ch] BYREF
  int v18; // [sp+18h] [bp-28h] BYREF
  unsigned int v19[8]; // [sp+20h] [bp-20h] BYREF

  v7 = 0;
  v18 = 0;
  if ( !a3 || (a3 & 0xFFFFFEAF) != 0 )
    goto LABEL_15;
  v9 = 260;
  for ( i = 260; ; v9 = i )
  {
    v11 = ExAllocatePoolWithTag(1, v9, 1380994640);
    v7 = (unsigned __int16 *)v11;
    if ( !v11 )
      break;
    v10 = CmGetDeviceContainerRegKeyPath(v11, a2, a3, v9 >> 1, v16, v11, v9 >> 1, v19);
    if ( v10 != -1073741789 )
      goto LABEL_9;
    ExFreePoolWithTag((unsigned int)v7);
    v7 = 0;
    v10 = RtlULongLongToULong(2 * v19[0], v19[0] >> 31, &i);
    if ( v10 < 0 )
      goto LABEL_16;
  }
  v10 = -1073741801;
LABEL_9:
  if ( v10 >= 0 )
  {
    if ( (a3 & 0x100) != 0 )
    {
      v13 = v7;
      v10 = PnpCtxRegOpenCurrentUserKey(a1);
      if ( v10 < 0 )
        goto LABEL_16;
      v14 = 0;
      goto LABEL_23;
    }
    v10 = RtlInitUnicodeStringEx((int)v19, v7);
    if ( v10 >= 0 )
    {
      if ( LOWORD(v19[0]) >= v9 || LOWORD(v19[0]) <= 0x32u || !RtlPrefixUnicodeString(L"24", (unsigned __int16 *)v19, 1) )
      {
LABEL_15:
        v10 = -1073741811;
        goto LABEL_16;
      }
      v13 = v7 + 25;
      v10 = PnpCtxGetCachedContextBaseKey(a1, 4, &v18);
      if ( v10 >= 0 )
      {
        v14 = v18;
LABEL_23:
        if ( a5 )
          v15 = PnpCtxRegDeleteTree(a1, v14, v13);
        else
          v15 = PnpCtxRegDeleteKey(a1, v14, v13);
        if ( v15 != -1073741444 && v15 < 0 )
          v10 = v15;
        goto LABEL_16;
      }
    }
  }
LABEL_16:
  if ( v7 )
    ExFreePoolWithTag((unsigned int)v7);
  return v10;
}
