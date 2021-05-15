// HdlspKernelAddLogEntry 
 
int __fastcall HdlspKernelAddLogEntry(int a1, unsigned __int16 *a2)
{
  __int16 *v4; // r4
  unsigned int v5; // r0
  int v6; // r4
  int v7; // r5
  unsigned int v8; // r7
  unsigned int v9; // r6
  unsigned int v10; // r0
  unsigned __int16 v12[96]; // [sp+8h] [bp-C0h] BYREF

  switch ( a1 )
  {
    case 1:
      v4 = L"KRNL: Loading ";
      goto LABEL_22;
    case 2:
      v4 = L"KRNL: Load succeeded.";
      goto LABEL_22;
    case 3:
      v4 = L"KRNL: Load failed.";
      goto LABEL_22;
    case 4:
      v4 = L"KRNL: Failed to create event.";
      goto LABEL_22;
    case 5:
      v4 = L"KRNL: Failed to create object types.";
      goto LABEL_22;
    case 6:
      v4 = L"KRNL: Failed to create root directories.";
      goto LABEL_22;
    case 7:
      v4 = L"KRNL: Failed to initialize (phase 0) plug and play services.";
      goto LABEL_22;
    case 8:
      v4 = L"KRNL: Failed to initialize (phase 1) plug and play services.";
      goto LABEL_22;
    case 9:
      v4 = L"KRNL: Failed to initialize boot drivers.";
      goto LABEL_22;
    case 10:
      v4 = L"KRNL: Failed to locate system dll.";
      goto LABEL_22;
    case 11:
      v4 = L"KRNL: Failed to initialize system drivers.";
      goto LABEL_22;
    case 12:
      v4 = L"KRNL: Failed to reassign system root.";
      goto LABEL_22;
    case 13:
      v4 = L"KRNL: Failed to protect system partition.";
      goto LABEL_22;
    case 14:
      v4 = L"KRNL: Failed to UnicodeToAnsi system root.";
      goto LABEL_22;
    case 15:
      v4 = L"KRNL: Failed to AnsiToUnicode system root.";
      goto LABEL_22;
    case 16:
      v4 = L"KRNL: Failed to find any groups.";
      goto LABEL_22;
    case 18:
      v4 = L"KRNL: Failed waiting for boot devices to delete.";
      goto LABEL_22;
    case 19:
      v4 = L"KRNL: Failed waiting for boot devices to start.";
      goto LABEL_22;
    case 20:
      v4 = L"KRNL: Failed waiting for boot devices to reinit.";
      goto LABEL_22;
    case 21:
      v4 = L"KRNL: Failed marking boot partition.";
LABEL_22:
      wcscpy_s((char *)v12, 80, (char *)v4);
      break;
    default:
      v4 = 0;
      v12[0] = 0;
      break;
  }
  if ( a1 == 1 && a2 )
  {
    v5 = wcslen((unsigned __int16 *)v4);
    v6 = *((_DWORD *)a2 + 1);
    v7 = 79 - v5;
    v8 = *a2 >> 1;
    if ( v8 < 80 - v5 )
      v7 = *a2 >> 1;
    v9 = v5;
    memmove((int)&v12[v5], *((_DWORD *)a2 + 1), 2 * v7);
    if ( *(_WORD *)(v6 + 2 * v8 - 2) )
      v12[v7 + v9] = 0;
  }
  v10 = wcslen(v12);
  return HdlspDispatch(17, v12, 2 * (v10 + 1), 0, 0);
}
