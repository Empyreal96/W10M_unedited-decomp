// PiMarkDeviceTreeForReenumerationWorker 
 
int __fastcall PiMarkDeviceTreeForReenumerationWorker(int a1)
{
  if ( *(_DWORD *)(a1 + 172) == 776 )
    PipSetDevNodeFlags(a1, 8);
  return 0;
}
