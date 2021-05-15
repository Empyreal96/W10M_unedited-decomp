// _CmDeleteDeviceInterfaceRegKeyWorker 
 
int __fastcall CmDeleteDeviceInterfaceRegKeyWorker(int *a1, unsigned __int16 *a2, int a3, int a4, char a5)
{
  unsigned __int16 *v8; // r6
  unsigned int v10; // r5
  int v11; // r4
  unsigned __int16 *v12; // r0
  unsigned __int16 *v14; // r5
  int v15; // r1
  int v16; // r0
  int v17; // [sp+0h] [bp-48h]
  unsigned int v18; // [sp+14h] [bp-34h] BYREF
  int v19; // [sp+18h] [bp-30h] BYREF
  unsigned int v20[10]; // [sp+20h] [bp-28h] BYREF

  v8 = 0;
  v19 = 0;
  if ( !a3 || (a3 & 0xFFFFFCCC) != 0 )
    goto LABEL_16;
  v10 = 480;
  v18 = 480;
  if ( (a3 & 0x200) != 0 )
  {
    v10 = 600;
    v18 = 600;
  }
  while ( 1 )
  {
    v12 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v10, 1380994640);
    v8 = v12;
    if ( !v12 )
      break;
    v11 = CmGetDeviceInterfaceRegKeyPath((int)v12, a2, a3, a4, v17, v12, v10 >> 1, v20);
    if ( v11 != -1073741789 )
      goto LABEL_10;
    ExFreePoolWithTag((unsigned int)v8);
    v8 = 0;
    v11 = RtlULongLongToULong(2 * v20[0], v20[0] >> 31, &v18);
    if ( v11 < 0 )
      goto LABEL_17;
    v10 = v18;
  }
  v11 = -1073741801;
LABEL_10:
  if ( v11 >= 0 )
  {
    if ( (a3 & 0x100) != 0 )
    {
      v14 = v8;
      v11 = PnpCtxRegOpenCurrentUserKey(a1);
      if ( v11 < 0 )
        goto LABEL_17;
      v15 = 0;
      goto LABEL_24;
    }
    v11 = RtlInitUnicodeStringEx((int)v20, v8);
    if ( v11 >= 0 )
    {
      if ( LOWORD(v20[0]) >= v10
        || LOWORD(v20[0]) <= 0x32u
        || !RtlPrefixUnicodeString(L"24", (unsigned __int16 *)v20, 1) )
      {
LABEL_16:
        v11 = -1073741811;
        goto LABEL_17;
      }
      v14 = v8 + 25;
      v11 = PnpCtxGetCachedContextBaseKey(a1, 4, &v19);
      if ( v11 >= 0 )
      {
        v15 = v19;
LABEL_24:
        if ( a5 )
          v16 = PnpCtxRegDeleteTree(a1, v15, v14);
        else
          v16 = PnpCtxRegDeleteKey(a1, v15, v14);
        if ( v16 != -1073741444 && v16 < 0 )
          v11 = v16;
        goto LABEL_17;
      }
    }
  }
LABEL_17:
  if ( v8 )
    ExFreePoolWithTag((unsigned int)v8);
  return v11;
}
