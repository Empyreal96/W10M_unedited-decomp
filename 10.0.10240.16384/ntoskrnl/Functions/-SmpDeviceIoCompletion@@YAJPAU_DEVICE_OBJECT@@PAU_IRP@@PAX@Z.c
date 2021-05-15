// -SmpDeviceIoCompletion@@YAJPAU_DEVICE_OBJECT@@PAU_IRP@@PAX@Z 
 
int __fastcall SmpDeviceIoCompletion(struct _DEVICE_OBJECT *a1, struct _IRP *a2, void *a3)
{
  int v4; // r1
  int v6; // r6
  unsigned int *v7; // r2
  unsigned int v8; // r1
  _DWORD *v9; // r0
  unsigned int v10; // r4
  unsigned int v11; // r1

  v4 = a2->IoStatus.Status;
  v6 = *((_DWORD *)a3 + 7);
  if ( v4 >= 0 )
  {
    if ( a2->IoStatus.Information >= *((_DWORD *)a3 + 6) )
      goto LABEL_5;
    v4 = -1073741435;
  }
  ST_STORE<SM_TRAITS>::StDeviceIoMarkFailed((_DWORD *)a3 + 1, v4);
LABEL_5:
  pIoFreeIrp(a2);
  if ( *((_DWORD *)a3 + 2) )
  {
    __dmb(0xBu);
    v7 = (unsigned int *)(v6 + 3576);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 - 1, v7) );
    __dmb(0xBu);
  }
  if ( (*((_DWORD *)a3 + 4) & 4) != 0 )
  {
    KeSetEvent(v6 + 3632, 1, 0);
  }
  else
  {
    SMKM_STORE<SM_TRAITS>::SmStWorkItemQueue(v6, (int)a3, 1);
    v9 = &SmGlobals[24 * (*(_DWORD *)(v6 + 3512) & 0x1F) + 1];
    __pld(v9);
    v10 = *v9 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v11 = __ldrex(v9);
    while ( v11 == v10 && __strex(v10 - 2, v9) );
    if ( v11 != v10 )
      ExfReleaseRundownProtection((unsigned __int8 *)v9);
  }
  return -1073741802;
}
