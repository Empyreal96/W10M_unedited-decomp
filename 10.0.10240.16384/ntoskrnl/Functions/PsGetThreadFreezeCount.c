// PsGetThreadFreezeCount 
 
int __fastcall PsGetThreadFreezeCount(int a1)
{
  return ((*(_DWORD *)(*(_DWORD *)(a1 + 336) + 100) >> 3) & 1) + *(_DWORD *)(*(_DWORD *)(a1 + 336) + 148);
}
