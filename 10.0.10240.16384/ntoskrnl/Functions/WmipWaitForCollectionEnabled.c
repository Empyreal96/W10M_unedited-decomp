// WmipWaitForCollectionEnabled 
 
int __fastcall WmipWaitForCollectionEnabled(int a1)
{
  if ( (*(_DWORD *)(a1 + 8) & 8) == 0 )
  {
    KeInitializeEvent(*(_DWORD *)(a1 + 64), 0, 0);
    *(_DWORD *)(a1 + 8) |= 8u;
  }
  KeReleaseMutex((int)&WmipSMMutex);
  KeWaitForSingleObject(*(_DWORD *)(a1 + 64), 0, 0, 0, 0);
  return KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
}
