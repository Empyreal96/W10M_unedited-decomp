// AdtpSubstituteDriveLetter 
 
int __fastcall AdtpSubstituteDriveLetter(int a1, int a2, int a3, int a4)
{
  int result; // r0
  _WORD *v6; // r5
  unsigned int v7; // r4
  int v8; // r1
  _DWORD v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a4;
  result = AdtpLookupDriveLetter(a1, v9, (char *)v9 + 2);
  if ( result )
  {
    v6 = *(_WORD **)(a1 + 4);
    v7 = (unsigned __int16)(*(_WORD *)a1 - LOWORD(v9[0]));
    v8 = (int)v6 + LOWORD(v9[0]);
    *v6 = HIWORD(v9[0]);
    v6[1] = 58;
    result = memmove((int)(v6 + 2), v8, v7);
    *(_WORD *)a1 = v7 + 4;
  }
  return result;
}
