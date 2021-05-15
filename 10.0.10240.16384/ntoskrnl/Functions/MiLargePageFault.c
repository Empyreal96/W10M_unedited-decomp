// MiLargePageFault 
 
int __fastcall MiLargePageFault(int a1, unsigned int a2, int a3, int a4)
{
  int *v5; // r9
  int v6; // r5
  int v9; // r10
  int v11; // r1
  int v12; // [sp+8h] [bp-C0h]
  int v13; // [sp+10h] [bp-B8h] BYREF
  char v14; // [sp+14h] [bp-B4h]
  char v15; // [sp+15h] [bp-B3h]
  int v16; // [sp+18h] [bp-B0h]
  int v17; // [sp+1Ch] [bp-ACh]
  int v18; // [sp+20h] [bp-A8h]
  int v19; // [sp+24h] [bp-A4h]

  a4 = (char)a4;
  v5 = (int *)(((a2 >> 20) & 0xFFC) - 1070596096);
  v6 = *v5;
  v12 = (char)a4;
  v9 = a3 & 1;
  if ( (a3 & 1) == 0 || *(_BYTE *)(a3 & 0xFFFFFFFE) != 1 )
  {
    if ( (a1 & 1) != 0 )
    {
      if ( (v6 & 0x80) == 0 )
        return -1073741819;
      if ( MiNoFaultFound(a1, (unsigned int *)(((a2 >> 20) & 0xFFC) - 1070596096), a2, 0, 0) )
      {
        v17 = 0;
        v13 = 1;
        v14 = 0;
        v15 = 0;
        v18 = 0;
        v16 = 33;
        v19 = 0;
        MiInsertTbFlushEntry((int)&v13, a2 & 0xFFC00000, 1, 1);
        MiFlushTbList((unsigned int)&v13, v11);
      }
      a4 = v12;
    }
    if ( (a1 & 8) != 0 )
    {
      if ( (v6 & 1) != 0 )
      {
        __mrc(15, 0, 13, 0, 3);
        return -1073741819;
      }
      if ( !a4 )
        MI_CHECK_KERNEL_NOEXECUTE_FAULT(a1, a2, a3, v6);
    }
    if ( v9 )
    {
      if ( *(_BYTE *)(a3 & 0xFFFFFFFE) == 5 )
      {
        MiValidVirtualizationFault(a3 & 0xFFFFFFFE, v5);
        *(_DWORD *)((a3 & 0xFFFFFFFE) + 20) += (a2 - (a2 & 0xFFC00000)) >> 12;
      }
    }
  }
  return 0;
}
