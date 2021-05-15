// sub_7DC21C 
 
void __fastcall sub_7DC21C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, _DWORD *a13, char a14)
{
  __int16 *v14; // r4
  unsigned __int16 *v15; // r5
  int v16; // r6
  int v17; // r7
  int v18; // r8
  __int16 v19; // r3

  if ( v17 || a14 )
  {
    *v14 = SepAdtClassifyObjectIntoSubCategory(v17, v15, v18, v16);
  }
  else
  {
    if ( v15 && RtlPrefixUnicodeString((unsigned __int16 *)&SepSamTypeNamePrefix, v15, 0) )
      v19 = 119;
    else
      v19 = 120;
    *v14 = v19;
  }
  SepAdtAuditThisEventWithContext((unsigned __int16)*v14, v18, v16, a13);
  JUMPOUT(0x6E8B1A);
}
