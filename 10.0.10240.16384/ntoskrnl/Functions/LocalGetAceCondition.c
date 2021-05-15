// LocalGetAceCondition 
 
int __fastcall LocalGetAceCondition(unsigned __int8 *a1, int a2, unsigned __int16 **a3, int *a4, _DWORD *a5)
{
  int v5; // r4
  int v7; // r6
  int v11; // r0
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r5
  int v17; // r0
  int v18; // r0

  v5 = *a1;
  v7 = 0;
  *a3 = 0;
  *a4 = 0;
  if ( v5 == 9 || v5 == 10 || v5 == 18 || v5 == 13 || v5 == 11 )
  {
    if ( v5 == 11 )
    {
      v11 = RtlLengthSid(a2);
      v12 = *((_DWORD *)a1 + 2);
      if ( (v12 & 1) != 0 )
        v13 = 16;
      else
        v13 = 0;
      if ( (v12 & 2) != 0 )
        v14 = 16;
      else
        v14 = 0;
      v15 = *((unsigned __int16 *)a1 + 1) - v14 - v13 - v11 - 12;
    }
    else
    {
      v15 = *((unsigned __int16 *)a1 + 1) - RtlLengthSid(a2) - 8;
    }
    *a4 = v15;
    v16 = v15;
    if ( v15 )
    {
      v17 = RtlLengthSid(a2);
      if ( v5 == 18 )
        v18 = LocalGetStringForRelativeAttribute(v17 + a2, v16);
      else
        v18 = LocalpGetStringForCondition(v17 + a2, v16, a3);
      v7 = v18;
      if ( !v18 )
        *a5 += 2 * (wcslen(*a3) + 1);
    }
  }
  return v7;
}
