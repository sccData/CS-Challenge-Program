1. 在 `/tmp` 下新建一个名为 `missing` 的文件夹。

   ```shell
   mkdir /tmp/missing
   ```

2. 用 `man` 查看程序 `touch` 的使用手册。

   ```shell
   man touch
   ```

   touch - 改变文件时间戳

   更新文件的访问和修改时间为当前时间。如果文件参数为空，则创建一个空文件。
   
3. 用 `touch` 在 `missing` 文件夹中新建一个叫 `semester` 的文件。

   ```shell
   touch /tmp/missing/semester
   ```

4. 将以下内容一行一行地写入 `semester` 文件：

   ```shell
   #!/bin/sh
    curl --head --silent https://missing.csail.mit.edu
   ```

   第一行可能有点棘手， `#` 在Bash中表示注释，而 `!` 即使被双引号（`"`）包裹也具有特殊的含义。 单引号（`'`）则不一样，此处利用这一点解决输入问题。

   ```shell
   echo '#!/bin/sh' > /tmp/missing/semester
   echo 'curl --head --silent https://missing.csail.mit.edu' >> /tmp/missing/semester
   ```

5. 尝试执行这个文件。例如，将该脚本的路径（`./semester`）输入到您的shell中并回车。如果程序无法执行，请使用 `ls` 命令来获取信息并理解其不能执行的原因。

   不行执行。

   ```shell
   -rw-r--r-- 1 scc scc 61 2月  11 15:41 semester
   ```

   从上面可以看出来，该文件没有执行权限。

6. 查看 `chmod` 的手册(例如，使用 `man chmod` 命令)

   chmod - 改变文件模式位

   GNU版本chmod。chmod既可以通过符号，也可以通过八进制数来改变模式位。

   符号模式的格式位```[ugoa...][[-+=][perms...]...]```

   - u 表示该文件的拥有者，g 表示与该文件的拥有者属于同一个群体(group)者，o 表示其他以外的人，a 表示这三者皆是。
   - \+ 表示增加权限、- 表示取消权限、= 表示唯一设定权限。
   - perms从集合rwxXst中选取, r表示读取, w表示可写入, x表示可执行

   chmod命令可以使用八进制数来指定权限。文件或目录的权限位是由9个权限位来控制，每三位为一组，它们分别是文件所有者（User）的读、写、执行，用户组（Group）的读、写、执行以及其它用户（Other）的读、写、执行。历史上，文件权限被放在一个比特掩码中，掩码中指定的比特位设为1，用来说明一个类具有相应的优先级。

7. 使用 `chmod` 命令改变权限，使 `./semester` 能够成功执行，不要使用 `sh semester` 来执行该程序。您的 shell 是如何知晓这个文件需要使用 `sh` 来解析呢？

   ```shell
   chmod u+x semester
   ```

   在计算机领域中, Shebang是一个由#!组成的字符序列,其出现在文本文件的第一行的前两个字符。在文件中存在shebang的情况下, 类Unix操作系统的程序加载器会分析Shebang后的内容, 将这些内容作为解释器指令, 并调用该指令, 并将载有Shebang的文件路径作为该解释器的参数。

8. 使用 `|` 和 `>` ，将 `semester` 文件输出的最后更改日期信息，写入/home目录下的 `last-modified.txt` 的文件中

   ```shell
   ./semester | grep last-modified > last-modified.txt
   ```
   
9. 写一段命令来从 `/sys` 中获取笔记本的电量信息，或者台式机 CPU 的温度。注意：macOS 并没有 sysfs，所以 Mac 用户可以跳过这一题。

   ```shell
   cat /sys/class/power_supply/BAT0/capacity
   ```

   
