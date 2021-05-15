// MiCreateVadEventBitmap 
 
int __fastcall MiCreateVadEventBitmap(int a1, int a2, unsigned int a3)
{
  int v6; // r7
  _DWORD *v7; // r5

  v6 = ((a3 & 0x1F) != 0) + (a3 >> 5) + 6;
  v7 = (_DWORD *)ExAllocatePoolWithTag(512, 4 * v6, 2004315469);
  if ( !v7 )
    return -1073741670;
  if ( PsChargeProcessNonPagedPoolQuota(a1, 4 * v6) < 0 )
    return sub_7D41A8();
  v7[1] = 4;
  v7[2] = a3;
  v7[3] = v7 + 6;
  RtlClearAllBits((int)(v7 + 2));
  MiInsertVadEvent(a2, v7, 1);
  return 0;
}
