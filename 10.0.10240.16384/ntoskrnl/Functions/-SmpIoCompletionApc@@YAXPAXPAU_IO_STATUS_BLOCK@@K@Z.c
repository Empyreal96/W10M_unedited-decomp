// -SmpIoCompletionApc@@YAXPAXPAU_IO_STATUS_BLOCK@@K@Z 
 
void __fastcall SmpIoCompletionApc(void *a1, struct _IO_STATUS_BLOCK *a2, unsigned int a3)
{
  struct _IO_STATUS_BLOCK *v3; // r4
  int v4; // r1
  unsigned int *v6; // r2
  unsigned int v7; // r1
  _DWORD *v8; // r0
  unsigned int v9; // r4
  unsigned int v10; // r1

  v3 = a2 - 3;
  v4 = a2->Status;
  if ( v4 < 0 )
    ST_STORE<SM_TRAITS>::StDeviceIoMarkFailed(&v3->Information, v4);
  if ( v3[1].Status )
  {
    __dmb(0xBu);
    v6 = (unsigned int *)((char *)a1 + 3576);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 - 1, v6) );
    __dmb(0xBu);
  }
  if ( (v3[2].Status & 4) != 0 )
  {
    KeSetEvent((int)a1 + 3632, 1, 0);
  }
  else
  {
    SMKM_STORE<SM_TRAITS>::SmStWorkItemQueue((int)a1, (int)v3, 1);
    v8 = &SmGlobals[24 * (*((_DWORD *)a1 + 878) & 0x1F) + 1];
    __pld(v8);
    v9 = *v8 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v10 = __ldrex(v8);
    while ( v10 == v9 && __strex(v9 - 2, v8) );
    if ( v10 != v9 )
      ExfReleaseRundownProtection((unsigned __int8 *)v8);
  }
}
