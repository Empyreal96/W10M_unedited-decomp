// MiUnmapLockedPagesInUserSpace 
 
_DWORD *__fastcall MiUnmapLockedPagesInUserSpace(unsigned int a1, _DWORD *a2, int a3, int a4)
{
  int *v4; // r5
  unsigned int v6; // r7
  _DWORD *result; // r0
  int v8; // r6
  int v9; // r1
  int v10; // lr
  unsigned int v11; // r2
  int v12; // t1
  int v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a4;
  v4 = a2 + 7;
  v6 = (a2[5] + (((unsigned __int16)a2[6] + (unsigned __int16)a2[4]) & 0xFFFu) + 4095) >> 12;
  result = (_DWORD *)MiObtainReferencedVad(a1, v13);
  if ( result )
  {
    v8 = result[7];
    v9 = result[3];
    if ( (v8 & 7) == 1 && (a1 & 0xFFFFF000) == v9 << 12 && v6 == result[4] - v9 + 1 )
    {
      v10 = ((a1 >> 10) & 0x3FFFFC) - (_DWORD)v4 - 0x40000000;
      while ( 1 )
      {
        v11 = *(int *)((char *)v4 + v10);
        v12 = *v4++;
        if ( v12 != v11 >> 12 )
          break;
        if ( !--v6 )
        {
          if ( (v8 & 0x4000) != 0 )
            result = (_DWORD *)sub_525FC0();
          else
            result = (_DWORD *)MiUnmapVad(result, 0);
          return result;
        }
      }
    }
    result = (_DWORD *)MiUnlockAndDereferenceVad(result);
  }
  return result;
}
