// PiPnpRtlGetDeviceRelationsList 
 
int __fastcall PiPnpRtlGetDeviceRelationsList(int a1, int a2, int a3, int a4, int a5)
{
  return PlugPlayGetDeviceRelations(a2, a3, a4, a5);
}
