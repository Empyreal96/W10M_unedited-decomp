// MiRemoveViewsFromSection 
 
int __fastcall MiRemoveViewsFromSection(int a1, int a2, unsigned int a3, int a4)
{
  int v7; // r7
  int v8; // r1
  int result; // r0

  v7 = 0;
  v8 = *(_DWORD *)(a1 + 60) - 1;
  *(_DWORD *)(a1 + 60) = v8;
  if ( !v8 && (*(_WORD *)(a1 + 18) & 1) == 0 )
    v7 = MiInsertUnusedSubsection(a1, 1);
  if ( !(a3 | a4) )
    JUMPOUT(0x54A896);
  if ( a4 || a3 > *(_DWORD *)(a1 + 28) )
    result = sub_54A890();
  else
    result = v7;
  return result;
}
