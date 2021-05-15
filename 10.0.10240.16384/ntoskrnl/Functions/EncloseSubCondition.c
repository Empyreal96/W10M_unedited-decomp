// EncloseSubCondition 
 
int __fastcall EncloseSubCondition(unsigned int *a1, int a2, int a3, int a4)
{
  unsigned __int16 *v5; // r0
  int v6; // r4
  unsigned int v7; // r0
  unsigned int v8; // r7
  _WORD *v9; // r0
  unsigned int v10; // r5
  int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a3;
  v12[1] = a4;
  v5 = (unsigned __int16 *)*a1;
  v12[0] = 0;
  v6 = 0;
  if ( *v5 != 40 )
  {
    v7 = wcslen(v5);
    if ( RtlULongLongToULong(2 * v7, (unsigned __int64)v7 >> 31, v12) < 0
      || (v8 = v12[0] + 6, (unsigned int)(v12[0] + 6) < v12[0]) )
    {
      v6 = 534;
    }
    else
    {
      v9 = SddlpAlloc(v12[0] + 6);
      v10 = (unsigned int)v9;
      if ( v9 )
      {
        if ( RtlStringCchPrintfW(v9, v8 >> 1, (int)L"(%ls)", *a1) >= 0 )
        {
          if ( *a1 )
            ExFreePoolWithTag(*a1);
          *a1 = v10;
        }
        else
        {
          ExFreePoolWithTag(v10);
          v6 = 50;
        }
      }
      else
      {
        v6 = 8;
      }
    }
  }
  return v6;
}
