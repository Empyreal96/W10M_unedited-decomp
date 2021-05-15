// PiSwFindBusRelations 
 
int __fastcall PiSwFindBusRelations(int *a1, int a2, int a3, int a4)
{
  int *v5; // [sp+0h] [bp-10h] BYREF
  int v6; // [sp+4h] [bp-Ch]
  int v7; // [sp+8h] [bp-8h]
  int v8; // [sp+Ch] [bp-4h]

  v5 = a1;
  v6 = a2;
  v7 = a3;
  v8 = a4;
  if ( !a1[1] )
    return 0;
  v5 = (int *)*a1;
  v6 = a1[1];
  return RtlLookupElementGenericTableAvl((int)&PiSwBusRelationsTable, (int)&v5);
}
