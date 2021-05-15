// SmWatchDogRegister 
 
unsigned int __fastcall SmWatchDogRegister(int a1, int a2, __int16 a3)
{
  return SmWdWorkItemRegister((int)dword_636188, *(_DWORD *)(a1 + 3512), a2, a3);
}
