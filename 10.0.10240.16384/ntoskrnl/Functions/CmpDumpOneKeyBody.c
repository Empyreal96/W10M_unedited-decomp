// CmpDumpOneKeyBody 
 
int __fastcall CmpDumpOneKeyBody(int a1, int a2, unsigned __int16 *a3, _DWORD *a4)
{
  int result; // r0
  _DWORD *v7; // r5
  int v8; // r6
  int v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = (int)a3;
  v9[1] = (int)a4;
  result = a2;
  if ( a4 )
  {
    v7 = (_DWORD *)a4[1];
    if ( a4[5] != a2 )
    {
      v8 = *a3 + 12;
      a4[2] += v8;
      if ( (int)a4[3] >= 0 )
      {
        if ( (unsigned int)(a4[4] + v8) <= *a4 )
        {
          v7[3 * *v7 + 1] = *(_DWORD *)(a2 + 12);
          LOWORD(v7[3 * *v7 + 2]) = *a3;
          HIWORD(v7[3 * *v7 + 2]) = *a3;
          v7[3 * *v7 + 3] = a4[6] - *a3;
          result = memmove(v7[3 * *v7 + 3], *((_DWORD *)a3 + 1), *a3);
          a4[6] -= *a3;
          a4[4] += v8;
        }
        else
        {
          a4[3] = -2147483643;
        }
      }
      ++*v7;
    }
  }
  else
  {
    if ( PsLookupProcessByProcessId(*(_DWORD *)(a2 + 12), v9) >= 0 )
      result = v9[0];
    else
      result = 0;
    if ( result )
      result = ObfDereferenceObjectWithTag(result);
  }
  return result;
}
