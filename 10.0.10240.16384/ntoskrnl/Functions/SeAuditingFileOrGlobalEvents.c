// SeAuditingFileOrGlobalEvents 
 
int __fastcall SeAuditingFileOrGlobalEvents(int a1, int a2, _DWORD *a3)
{
  int v6; // r3
  int v7; // r3
  int v8; // r3
  int v9; // r1
  int v11; // [sp+0h] [bp-20h] BYREF
  char v12[24]; // [sp+8h] [bp-18h] BYREF

  v11 = 0;
  RtlInitUnicodeString((unsigned int)v12, L"File");
  if ( SepRmGlobalSaclFind(&v11, 0, v12, 1) != -1073741772 )
    goto LABEL_9;
  if ( (*(_WORD *)(a2 + 2) & 0x10) == 0 )
    return 0;
  if ( (*(_WORD *)(a2 + 2) & 0x8000) != 0 )
  {
    v6 = *(_DWORD *)(a2 + 12);
    if ( v6 )
    {
      v7 = v6 + a2;
      goto LABEL_7;
    }
    return 0;
  }
  v7 = *(_DWORD *)(a2 + 12);
LABEL_7:
  if ( !v7 )
    return 0;
LABEL_9:
  if ( SepAdtAuditThisEventWithContext(0x74u, a1, a1 == 0, a3)
    || SepAdtAuditThisEventWithContext(0x81u, a1, a1 == 0, a3) )
  {
    goto LABEL_15;
  }
  v9 = a1 != 0;
  if ( !a1 )
    v9 |= 0x10u;
  if ( SepAdtAuditThisEventByCategoryWithContext(3, v9) )
LABEL_15:
    v8 = 1;
  else
    v8 = 0;
  return v8;
}
