// IoSetIoPriorityHint 
 
int __fastcall IoSetIoPriorityHint(int a1, unsigned int a2)
{
  if ( a2 >= 5 )
    return -1073741811;
  *(_DWORD *)(a1 + 8) = *(_DWORD *)(a1 + 8) & 0xFFF1FFFF | ((a2 + 1) << 17);
  return 0;
}
