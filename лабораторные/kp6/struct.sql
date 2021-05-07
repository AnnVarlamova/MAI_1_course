CREATE TABLE computer
(
    id int,
    surname varchar(30) NOT NULL,
    processors int NOT NULL,
    proc_type varchar(30) NOT NULL,
    memory_size int NOT NULL,
    video_controller_type varchar(30) NOT NULL,
    vid_mem_size int NOT NULL,
    HMDD_type varchar(30) NOT NULL,
    HMDD_number int NOT NULL,
    HMDD_size int NOT NULL,
    controllers_number int NOT NULL,
    devices_number int NOT NULL,
    OS varchar(30) NOT NULL
  );
  INSERT computer 
  VALUES (1, 'Smirnova', 1, 'Intel_Core', 4, 'integrated', 512, 'SATA', 1, 128, 1, 4, 'Windows10'),
  
  (2, 'Ivanov', 2, 'Intel_Xeon', 32, 'integrated', 2048, 'SAS', 4, 1024, 2, 300, 'Windows_Server');

SELECT * FROM computer
WHERE (proc_type IN ('Intel_Xeon', 'AMD_Opteron', 'Intel_Atom', 'Intel_Itanium')
AND OS IN ('Free_BSD', 'Windows_Server', 'CentOS', 'Ubuntu_Server', 'Gentoo', 'Fedora', 'OS_X_Server',
'OpenBSD', 'Solaris', 'HO-US', 'AIX')) AND (processors > 1 OR memory_size >= 16 OR HMDD_number > 1
                                    OR HMDD_size >= 1024 OR devices_number > 15);