// SepAuditTypeList 
 
unsigned int __fastcall SepAuditTypeList(int a1, unsigned int a2, int a3, int a4, _BYTE *a5, _BYTE *a6)
{
  BOOL v8; // r4
  unsigned int result; // r0
  int v10; // r9
  unsigned __int16 *v11; // r1
  int *v12; // r5
  int v13; // r3
  unsigned __int16 v14; // r3

  v8 = *(_DWORD *)(a3 + 4 * a4) >= 0;
  result = a4 + 1;
  if ( a4 + 1 < a2 )
  {
    v10 = 44 * a4;
    v11 = (unsigned __int16 *)(a1 + 44 * result);
    v12 = (int *)(a3 + 4 * result);
    do
    {
      if ( *v11 <= (unsigned int)*(unsigned __int16 *)(v10 + a1) )
        return result;
      v13 = *v12;
      if ( v8 )
      {
        if ( v13 < 0 )
        {
          *a6 = 1;
          v14 = v11[1] | 2;
LABEL_9:
          v11[1] = v14;
          goto LABEL_10;
        }
      }
      else if ( v13 >= 0 )
      {
        *a5 = 1;
        v14 = v11[1] | 1;
        goto LABEL_9;
      }
LABEL_10:
      ++result;
      ++v12;
      v11 += 22;
    }
    while ( result < a2 );
  }
  return result;
}
