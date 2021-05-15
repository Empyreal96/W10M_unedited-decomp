// CmpClearKeyAccessBits 
 
int __fastcall CmpClearKeyAccessBits(int a1)
{
  _DWORD *v2; // r0
  int v4; // r4

  v2 = (_DWORD *)ExAllocatePoolWithTag(1, 4096, 830106947);
  if ( !v2 )
    return -1073741670;
  *v2 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 36);
  v2[1] = 0;
  if ( *v2 != -1 )
    return sub_7EB2D8();
  v4 = 0;
  ExFreePoolWithTag((unsigned int)v2);
  return v4;
}
