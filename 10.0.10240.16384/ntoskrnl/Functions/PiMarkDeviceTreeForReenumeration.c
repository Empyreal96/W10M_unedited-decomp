// PiMarkDeviceTreeForReenumeration 
 
int __fastcall PiMarkDeviceTreeForReenumeration(int a1, int a2)
{
  int result; // r0
  int v5; // r3

  result = PiMarkDeviceTreeForReenumerationWorker(a1, 0);
  if ( a2 )
    result = PipForDeviceNodeSubtree(a1, (int)PiMarkDeviceTreeForReenumerationWorker, 0, v5);
  return result;
}
