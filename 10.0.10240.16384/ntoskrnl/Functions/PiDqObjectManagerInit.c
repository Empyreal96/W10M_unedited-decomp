// PiDqObjectManagerInit 
 
int __fastcall PiDqObjectManagerInit(int a1, int a2)
{
  int result; // r0

  memset((_BYTE *)a1, 0, 132);
  *(_DWORD *)(a1 + 128) = a2;
  ExInitializeResourceLite(a1);
  result = KeInitializeGuardedMutex(a1 + 56);
  *(_DWORD *)(a1 + 104) = a1 + 104;
  *(_DWORD *)(a1 + 108) = a1 + 104;
  *(_DWORD *)(a1 + 112) = a1 + 112;
  *(_DWORD *)(a1 + 116) = a1 + 112;
  *(_DWORD *)(a1 + 96) = PiDqObjectManagerServiceActionQueue;
  *(_DWORD *)(a1 + 100) = a1;
  *(_DWORD *)(a1 + 88) = 0;
  return result;
}
