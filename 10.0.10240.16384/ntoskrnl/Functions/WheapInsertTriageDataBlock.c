// WheapInsertTriageDataBlock 
 
int __fastcall WheapInsertTriageDataBlock(_DWORD *a1, int a2, unsigned int a3)
{
  _DWORD *v6; // r4
  unsigned int v7; // r5
  int v8; // r7
  char *v9; // r1
  unsigned int v10; // r7
  unsigned int v11; // r6
  unsigned int v12; // lr
  unsigned int v13; // r2
  unsigned int v14; // r1
  char *i; // r2
  unsigned int v16; // r6

  v6 = a1 + 1024;
  if ( (a1[995] & 0x800) != 0 )
  {
    v7 = a1[1049];
    if ( v7 )
    {
      v8 = a1[1048];
      if ( v8 + 16 * v7 <= 0x20000 )
      {
        v9 = (char *)a1 + v8;
        v10 = 0;
        v11 = 0;
        v12 = 0x20000;
        while ( 1 )
        {
          v13 = *((_DWORD *)v9 + 2);
          if ( v13 != ((v13 + 7) & 0xFFFFFFF8) )
            break;
          if ( v13 < v12 )
            v12 = *((_DWORD *)v9 + 2);
          if ( ((*((_DWORD *)v9 + 3) + v13 + 7) & 0xFFFFFFF8) > v11 )
            v11 = (*((_DWORD *)v9 + 3) + v13 + 7) & 0xFFFFFFF8;
          ++v10;
          v9 += 16;
          if ( v10 >= v7 )
          {
            if ( 131068 - v11 >= 0x20000 || ((a3 + 7) & 0xFFFFFFF8) + 16 > 131068 - v11 )
              return -1073741789;
            memmove((int)a1 + v12 + 16, (int)a1 + v12, v11 - v12);
            v14 = 0;
            for ( i = (char *)a1 + v6[24]; v14 < v6[25]; i += 16 )
            {
              ++v14;
              *((_DWORD *)i + 2) += 16;
            }
            v16 = v11 + 16;
            ++v6[25];
            *(_QWORD *)i = a2;
            *((_DWORD *)i + 2) = v16;
            *((_DWORD *)i + 3) = a3;
            memmove((int)a1 + v16, a2, a3);
            return 0;
          }
        }
      }
    }
  }
  return -1073741811;
}
