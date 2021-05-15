// sub_7DC4F8 
 
void __fastcall sub_7DC4F8(int a1, int a2, int a3, int a4, __int16 a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, __int16 *a15)
{
  int v15; // r4
  unsigned int *v16; // r8
  int v17; // r9
  __int16 v18; // r2

  if ( SepFilterPrivilegeAudits(0, (int *)v16) )
  {
    if ( v17 && v15 && v16 && *v16 || (SepAdtCheckPrivilegeForSensitivity(v16, &a5, (_BYTE *)&a5 + 1), v17) && (_BYTE)a5 )
    {
      v18 = 130;
LABEL_12:
      *a15 = v18;
      goto LABEL_13;
    }
    if ( v15 && HIBYTE(a5) )
    {
      v18 = 131;
      goto LABEL_12;
    }
  }
LABEL_13:
  JUMPOUT(0x6E8C3A);
}
