// PopPepTriggerComponentActiveActivity 
 
void __fastcall PopPepTriggerComponentActiveActivity(int a1, int a2)
{
  if ( a2 )
  {
    *(_DWORD *)(a2 + 4) |= 1u;
    **(_DWORD **)(a2 + 60) = 4;
  }
}
