// IopBusNumberUnpackResource 
 
int __fastcall IopBusNumberUnpackResource(int a1, _QWORD *a2, _QWORD *a3)
{
  *a2 = *(unsigned int *)(a1 + 4);
  *a3 = *(unsigned int *)(a1 + 8);
  return 0;
}
