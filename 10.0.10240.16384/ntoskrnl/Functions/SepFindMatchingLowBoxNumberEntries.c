// SepFindMatchingLowBoxNumberEntries 
 
int __fastcall SepFindMatchingLowBoxNumberEntries(_DWORD *a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  int v9; // r5
  int v10; // r4
  int v11; // r3
  bool v12; // zf
  _DWORD *v13; // r0
  int result; // r0
  int v15[12]; // [sp+0h] [bp-30h] BYREF

  *a5 = 0;
  v9 = 0;
  v10 = 0;
  v15[0] = 0;
  v15[1] = 0;
  v15[2] = 0;
  v15[3] = 0;
  v15[4] = 0;
  *a4 = 0;
  if ( RtlInitEnumerationHashTable((int)a1, (int)v15, a3, 0) )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v13 = RtlEnumerateEntryHashTable(a1, v15);
        if ( !v13 )
        {
LABEL_9:
          RtlEndEnumerationHashTable((int)a1, v15);
          goto LABEL_10;
        }
        v11 = v13[5];
        if ( v11 != a2 )
          break;
        v9 = 1;
        v12 = v10 == 1;
        *a4 = v13;
LABEL_7:
        if ( v12 )
          goto LABEL_9;
      }
      if ( v11 == a3 )
      {
        v10 = 1;
        v12 = v9 == 1;
        *a5 = v13;
        goto LABEL_7;
      }
    }
  }
LABEL_10:
  if ( v9 == 1 && v10 == 1 )
    result = 0;
  else
    result = -1073741275;
  return result;
}
