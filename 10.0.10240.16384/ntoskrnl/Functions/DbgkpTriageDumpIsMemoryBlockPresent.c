// DbgkpTriageDumpIsMemoryBlockPresent 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall DbgkpTriageDumpIsMemoryBlockPresent(_DWORD *a1, unsigned int a2, int a3, unsigned int a4)
{
  unsigned int v7; // r4 OVERLAPPED
  unsigned int v8; // r1
  int v9; // r3
  int v10; // r2
  unsigned int v11[6]; // [sp+0h] [bp-18h] BYREF

  v11[0] = a3;
  v11[1] = a4;
  if ( a1[6] && a1[7] < 0x6F9u )
  {
    if ( DbgkpTriageDumpCheckPresentHashTable((int)a1, a2, a3, v11) )
      return 1;
  }
  else
  {
    *(_QWORD *)(&v7 - 1) = *(_QWORD *)(*a1 + 4192);
    v8 = 0;
    v10 = *a1 + v9;
    if ( v7 )
    {
      while ( *(_QWORD *)v10 != a2 || a3 && *(_DWORD *)(v10 + 12) != a3 )
      {
        ++v8;
        v10 += 16;
        if ( v8 >= v7 )
          return 0;
      }
      return 1;
    }
  }
  return 0;
}
