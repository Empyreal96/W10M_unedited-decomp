// KsepCacheDeviceInsertData 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KsepCacheDeviceInsertData(int a1, unsigned __int16 *a2, int a3, int a4, unsigned int a5)
{
  int v9; // r0
  int v10; // r4
  int v11; // r5
  int v13; // r0
  int *v14; // r1

  v9 = KsepPoolAllocatePaged(28);
  v10 = v9;
  if ( !v9 )
    return -1073741801;
  v11 = KsepStringDuplicate(v9 + 8, a2);
  if ( v11 >= 0 )
  {
    v13 = KsepPoolAllocatePaged(a5);
    *(_DWORD *)(v10 + 24) = v13;
    if ( v13 )
    {
      memmove(v13, a3, a5);
      *(_QWORD *)(v10 + 16) = *(_QWORD *)(&a4 - 1);
      v14 = *(int **)(a1 + 32);
      *(_DWORD *)v10 = a1 + 28;
      *(_DWORD *)(v10 + 4) = v14;
      if ( *v14 != a1 + 28 )
        __fastfail(3u);
      *v14 = v10;
      *(_DWORD *)(a1 + 32) = v10;
      v10 = 0;
      v11 = 0;
    }
    else
    {
      v11 = -1073741801;
    }
  }
  if ( v10 )
  {
    KsepStringFree((_DWORD *)(v10 + 8));
    KsepPoolFreePaged(*(_DWORD *)(v10 + 24));
    KsepPoolFreePaged(v10);
  }
  return v11;
}
