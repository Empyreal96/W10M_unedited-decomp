// SeReportSecurityEventWithSubCategory 
 
int __fastcall SeReportSecurityEventWithSubCategory(int a1, unsigned __int16 *a2, int a3, int a4, int a5)
{
  int v5; // r5
  unsigned int v8; // r9
  int v10; // r3
  int *v11; // r0
  int v12[178]; // [sp+0h] [bp-2C8h] BYREF

  v5 = 0;
  if ( a1
    || !a2
    || !*((_DWORD *)a2 + 1)
    || !*a2
    || !a4
    || (unsigned int)(a5 - 100) > 0x39
    || *(_DWORD *)(a4 + 8) > 0x1Cu
    || (*(_WORD *)(a4 + 18) & 0x18) == 0 )
  {
    return -1073741811;
  }
  v8 = KeGetCurrentIrql(*a2);
  if ( v8 >= 2 )
  {
    if ( SepAuditingForSubCategory(a5, *(unsigned __int16 *)(a4 + 18) == 8) )
      return sub_52A734();
    goto LABEL_12;
  }
  if ( a3 )
  {
    v5 = a3;
  }
  else
  {
    SeCaptureSubjectContext(v12);
    v10 = v12[0];
    if ( !v12[0] )
      v10 = v12[2];
    v5 = **(_DWORD **)(v10 + 148);
    if ( v5 )
    {
      v11 = v12;
      goto LABEL_19;
    }
  }
  v11 = 0;
LABEL_19:
  if ( SepAdtAuditThisEventWithContext(
         a5,
         *(unsigned __int16 *)(a4 + 18) == 8,
         *(unsigned __int16 *)(a4 + 18) == 16,
         v11) )
  {
    JUMPOUT(0x52A73E);
  }
LABEL_12:
  if ( v8 < 2 && v5 && v5 != a3 )
    SeReleaseSubjectContext(v12);
  return 0;
}
