// PiDmGetObjectListCallback 
 
int __fastcall PiDmGetObjectListCallback(int a1, int a2, _BYTE *a3, int a4)
{
  int v4; // r5
  unsigned int v8; // r0
  __int64 v9; // kr00_8
  unsigned int v10; // r7
  int v11[6]; // [sp+8h] [bp-18h] BYREF

  v11[0] = a4;
  v4 = 0;
  *a3 = 0;
  if ( !*(_DWORD *)a2
    || (v4 = (*(int (__fastcall **)(int, _DWORD, int *))a2)(a1, *(_DWORD *)(a2 + 4), v11), v4 >= 0) && LOBYTE(v11[0]) )
  {
    v8 = wcslen(*(unsigned __int16 **)(a1 + 12));
    v9 = *(_QWORD *)(a2 + 12);
    v10 = v8 + 1;
    *(_DWORD *)(a2 + 16) = HIDWORD(v9) + v8 + 1;
    if ( (unsigned int)v9 > v8 + 1 )
    {
      RtlStringCchCopyExW(*(_WORD **)(a2 + 8), v9, *(_DWORD *)(a1 + 12), 0);
      *(_DWORD *)(a2 + 8) += 2 * v10;
      *(_DWORD *)(a2 + 12) -= v10;
    }
  }
  return v4;
}
